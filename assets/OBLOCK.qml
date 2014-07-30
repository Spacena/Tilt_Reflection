import bb.cascades 1.2
import bb.device 1.0
import bb 1.0
import QtMobility.sensors 1.2


Container {
    verticalAlignment: VerticalAlignment.Fill
    horizontalAlignment: HorizontalAlignment.Fill
    onCreationCompleted: {
        timer.start()
    }
    property int tiltAngle: 0    
    
    attachedObjects: [
        BatteryInfo {
            id: battery
        },
        MemoryInfo {
            id: memory
        },
        Timer {
            id: timer
            interval: 1000
            onTimeout: {
                currTime.text = "Time: " + timer.curTimeHour() + ":" + timer.curTimeMinute() + ":" + timer.curTimeSecond()
            }
        },
        Calendar {
            id: calendar
        },
        OrientationHandler {
            onDisplayDirectionChanged: { 
                OrientationSupport.supportedDisplayOrientation = 
                SupportedDisplayOrientation.CurrentLocked;
            }
        },
        
        RotationSensor {
            active: true
            onReadingChanged: {
                // When we tilt the device backwards, we add a sense of stiffness of 8 degrees 
                // before it actually changes the tiltAngle property (a.k.a. dead zone)
                var deadZoneAngle = 8
                
                if(tiltAngle >= reading.y && tiltAngle > (reading.y + deadZoneAngle)){
                    tiltAngle = reading.y;
                }
                else if (tiltAngle < reading.y) {
                    tiltAngle = reading.y;
                }
            
            }
        
        }
    ]        
    
    Container {
        layout: DockLayout {}
        preferredHeight: 530
        verticalAlignment: VerticalAlignment.Fill
        horizontalAlignment: HorizontalAlignment.Fill
        bottomPadding: 30
    
    }
    
    Container {
        horizontalAlignment: HorizontalAlignment.Fill        
        
        ColoredBlock {
            id: timeCB
            backgroundColor: Color.create("#da2128")
            
            Container {
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                Label {
                    id: currTime
                    text: "Time: " + timer.curTimeHour() + ":" + timer.curTimeMinute() + ":" + timer.curTimeSecond()
                    scaleX: -1.0
                    textStyle.fontWeight: FontWeight.Bold
                    textStyle.fontSize: FontSize.XLarge
                
                }
            }
            verticalAlignment: VerticalAlignment.Center
            opacity: (tiltAngle > -125) ? 1 : 0
        }
        ColoredBlock {
            id: dateCB
            backgroundColor: Color.create("#f68b28")
            
            Container {
                rightPadding: 100
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                Label {
                    text: "Date: " + (new Date()).toDateString()
                    scaleX: -1.0
                    verticalAlignment: VerticalAlignment.Center
                    textStyle.fontWeight: FontWeight.Bold
                    textStyle.fontSize: FontSize.XLarge
                
                }
            }
            verticalAlignment: VerticalAlignment.Center
            opacity: (tiltAngle > -135) ? 1 : 0
        }
        ColoredBlock {
            id: calendarCB
            backgroundColor: Color.create("#ffe710")
            
            Container {
                leftPadding: 100
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                ListView {
                    dataModel: calendar.model
                    scaleX: -1.0
                    topPadding: 20
                    verticalAlignment: VerticalAlignment.Center
                    
                    listItemComponents: ListItemComponent {
                        type: "item"
                        
                        StandardListItem {
                            title: "<html><b><span style='font-size:xx-large'>"+"Next event: "+ListItemData.subject+"</span></b></html>"
                        
                        }
                    }
                }
            }
            verticalAlignment: VerticalAlignment.Center
            opacity: (tiltAngle > -145) ? 1 : 0
        }           
        ColoredBlock {
            id: memoryCB
            backgroundColor: Color.create("#8cc747")
            
            Container {
                rightPadding: 100
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                Label {
                    text: "RAM Left: " + Math.round((memory.availableDeviceMemory()/1073741824)*1000)/1000 + " " + "GB"
                    scaleX: -1.0
                    verticalAlignment: VerticalAlignment.Center
                    textStyle.fontWeight: FontWeight.Bold
                    textStyle.fontSize: FontSize.XLarge
                }
            }
            verticalAlignment: VerticalAlignment.Center
            opacity: (tiltAngle > -155) ? 1 : 0
        }            
        ColoredBlock {
            id: batteryCB
            backgroundColor: Color.create("#00a95c")
            bottomPadding: 30
            
            Container {
                leftPadding: 100
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                
                Label {
                    text: "Battery: " + battery.level + "%"
                    scaleX: -1.0
                    verticalAlignment: VerticalAlignment.Center
                    textStyle.fontWeight: FontWeight.Bold
                    textStyle.fontSize: FontSize.XLarge
                }
            }
            verticalAlignment: VerticalAlignment.Center
            opacity: (tiltAngle > -165) ? 1 : 0
        }        
    }
}
