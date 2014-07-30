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
                
                if(tiltAngle >= reading.x && tiltAngle > (reading.x + deadZoneAngle)){
                    tiltAngle = reading.x;
                }
                else if (tiltAngle < reading.x) {
                    tiltAngle = reading.x;
                }
            
            }
        
        }
    ]        
    
    
    Container {
        horizontalAlignment: HorizontalAlignment.Fill        
        
        ColoredBlock {
            backgroundColor: Color.create("#da2128")
            
            Container {
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                Label {
                    id: currTime
                    text: "Time: " + timer.curTimeHour() + ":" + timer.curTimeMinute() + ":" + timer.curTimeSecond()
                    scaleX: -1.0
                    rotationZ: 180
                    textStyle.fontWeight: FontWeight.Bold
                    textStyle.fontSize: FontSize.XLarge
                
                }
            }
            verticalAlignment: VerticalAlignment.Center
            visible: (tiltAngle > 41 || (tiltAngle > 0 && tiltAngle < 8)) ? 1 : 0
        }
        ColoredBlock {
            backgroundColor: Color.create("#f68b28")
            
            Container {
                rightPadding: 100
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                Label {
                    text: "Date: " + (new Date()).toDateString()
                    scaleX: -1.0
                    rotationZ: 180
                    verticalAlignment: VerticalAlignment.Center
                    textStyle.fontWeight: FontWeight.Bold
                    textStyle.fontSize: FontSize.XLarge
                
                }
            }
            verticalAlignment: VerticalAlignment.Center
            visible: (tiltAngle > 35 || (tiltAngle > 0 && tiltAngle < 8)) ? 1 : 0
        }
        ColoredBlock {
            backgroundColor: Color.create("#ffe710")
            
            Container {
                leftPadding: 100
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                ListView {
                    dataModel: calendar.model
                    scaleX: -1.0
                    rotationZ: 180
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
            visible: (tiltAngle > 29 || (tiltAngle > 0 && tiltAngle < 8)) ? 1 : 0
        }           
        ColoredBlock {
            backgroundColor: Color.create("#8cc747")
            
            Container {
                rightPadding: 100
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                Label {
                    text: "RAM Left: " + Math.round((memory.availableDeviceMemory()/1073741824)*1000)/1000 + " " + "GB"
                    scaleX: -1.0
                    rotationZ: 180
                    verticalAlignment: VerticalAlignment.Center
                    textStyle.fontWeight: FontWeight.Bold
                    textStyle.fontSize: FontSize.XLarge
                }
            }
            verticalAlignment: VerticalAlignment.Center
            visible: (tiltAngle > 23 || (tiltAngle > 0 && tiltAngle < 8)) ? 1 : 0
        }            
        ColoredBlock {
            backgroundColor: Color.create("#00a95c")
            bottomPadding: 30
            
            Container {
                leftPadding: 100
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                
                Label {
                    text: "Battery: " + battery.level + "%"
                    scaleX: -1.0
                    rotationZ: 180
                    verticalAlignment: VerticalAlignment.Center
                    textStyle.fontWeight: FontWeight.Bold
                    textStyle.fontSize: FontSize.XLarge
                }
            }
            verticalAlignment: VerticalAlignment.Center
            visible: (tiltAngle > 15 || (tiltAngle > 0 && tiltAngle < 8)) ? 1 : 0
        }
        Divider {
            
        }
        ColoredBlock {
            background: Color.create("#000000");
            Container {
               
            }
            visible: (tiltAngle <= 60) ? 1 : 0
        }     
        ColoredBlock {
            background: Color.create("#000000");
            Container {
              
            }
            visible: (tiltAngle <= 50) ? 1 : 0
        }   
        ColoredBlock {
            background: Color.create("#000000");
            Container {
               
            }
            visible: (tiltAngle <= 40) ? 1 : 0
        }
        ColoredBlock {
            background: Color.create("#000000");
            Container {
               
            }
            visible: (tiltAngle <= 30) ? 1 : 0
        }
    }
}
