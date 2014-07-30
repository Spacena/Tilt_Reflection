/*
 * Copyright (c) 2011-2013 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import bb.cascades 1.2

Page {
    Container {
        ControlDelegate {
            id: cDelegate
            source: mySettings.tilt == 1 ? "OBLOCK.qml" : "VBLOCK.qml"
        }
    }
    Menu.definition: MenuDefinition {
        
        // Specify the actions that should be included in the menu
        helpAction: HelpActionItem {
            onTriggered: {
                helpSheet.open();
            }
        }
        settingsAction: SettingsActionItem {
            onTriggered: {
                settingsSheet.open();
            }
        }
    }
    attachedObjects: [
        Sheet {
            id: helpSheet
            NavigationPane {
                id: navPan
                Page {
                    Container {
                        layout: DockLayout {
                        }
                        
                        ImageView {
                            imageSource: "asset:///images/about.jpg"
                            horizontalAlignment: HorizontalAlignment.Fill
                            verticalAlignment: VerticalAlignment.Fill
                        }
                        ScrollView {
                            scrollViewProperties.scrollMode: ScrollMode.Vertical
                            Container {
                                leftPadding: 40
                                rightPadding: leftPadding
                                topPadding: 50
                                bottomPadding: topPadding
                                horizontalAlignment: HorizontalAlignment.Center
                                verticalAlignment: VerticalAlignment.Center
                                Label {
                                    text: "Just flip the device with screen facing down to see the reflection on some shining surface. As you tilt the device, you see different information on the surface.

You've the option to choose what type of Tilt you want via Settings.

If you liked this app then please don't forget to rate it.

Check out my other Built for BlackBerry certified apps."
                                                                        
                                                                        multiline: true
                                                                        horizontalAlignment: HorizontalAlignment.Center
                                                                        verticalAlignment: VerticalAlignment.Center
                                                                        textStyle.fontSize: FontSize.Medium
                                                                        textStyle.color: Color.White
                                                                        textStyle.fontStyle: FontStyle.Italic
                                                                        bottomMargin: 70
                                }
                                Container {
                                    layout: StackLayout {
                                        orientation: LayoutOrientation.LeftToRight
                                    }
                                    bottomPadding: 40
                                    Button {
                                        text: "howZapp"
                                        layoutProperties: StackLayoutProperties {
                                            spaceQuota: 1
                                        }
                                        onClicked: {
                                            invokeh.trigger("bb.action.OPEN")
                                        }
                                        attachedObjects: [
                                            Invocation {
                                                id: invokeh
                                                query {
                                                    mimeType: "application/x-bb-appworld"
                                                    uri: "appworld://content/44940913"
                                                }
                                            }
                                        ]
                                    }
                                    Button {
                                        text: "Battery"
                                        layoutProperties: StackLayoutProperties {
                                            spaceQuota: 1
                                        }
                                        onClicked: {
                                            invokeb.trigger("bb.action.OPEN")
                                        }
                                        attachedObjects: [
                                            Invocation {
                                                id: invokeb
                                                query {
                                                    mimeType: "application/x-bb-appworld"
                                                    uri: "appworld://content/38114900"
                                                }
                                            }
                                        ]
                                    }
                                    Button {
                                        text: "Browse"
                                        layoutProperties: StackLayoutProperties {
                                            spaceQuota: 1
                                        }
                                        onClicked: {
                                            invokebr.trigger("bb.action.OPEN")
                                        }
                                        attachedObjects: [
                                            Invocation {
                                                id: invokebr
                                                query {
                                                    mimeType: "application/x-bb-appworld"
                                                    uri: "appworld://content/39594935"
                                                }
                                            }
                                        ]
                                    }
                                }
                                Button {
                                    onClicked: {
                                        var blogpage = goToWebView.createObject();
                                        navPan.push(blogpage);
                                    }
                                    attachedObjects: ComponentDefinition {
                                        id: goToWebView
                                        source: "help.qml"
                                    }
                                    text: "View Privacy Policy"
                                    horizontalAlignment: HorizontalAlignment.Center
                                    verticalAlignment: VerticalAlignment.Bottom
                                }
                            }
                        }
                    }
                    actions: [
                        ActionItem {
                            title: "Close"
                            imageSource: "asset:///images/ic_done.png"
                            ActionBar.placement: ActionBarPlacement.OnBar
                            onTriggered: {
                                helpSheet.close();
                            }
                        }
                    ]
                }
            }
        },
        Sheet {
            id: settingsSheet
            Page {
                Container {
                    layout: DockLayout {
                    }
                    ImageView {
                        imageSource: "asset:///images/lockSheet.jpg"
                        horizontalAlignment: HorizontalAlignment.Fill
                        verticalAlignment: VerticalAlignment.Fill
                    }
              ScrollView {
               Container {
                   
                   topPadding: 50
                   bottomPadding: topPadding
                   
                Container {
                    preferredHeight: 5
                    horizontalAlignment: HorizontalAlignment.Fill
                    background: Color.DarkCyan
                }
                
                DropDown {
                    id: dropDown
                    title: "Tilt mode"
                    onSelectedIndexChanged: {
                        mySettings.tilt = dropDown.at(dropDown.selectedIndex).value;
                    }
                    
                    Option {
                        text: "Regular"
                        value: 1
                        selected: (mySettings.tilt == 1 ? true : false)
                    }
                    Option {
                        text: "Sliding"
                        value: 2
                        selected: (mySettings.tilt == 2 ? true : false)
                    }
                }
                
            }
            }
          }
            actions: [
                ActionItem {
                    title: "Close"
                    imageSource: "asset:///images/ic_done.png"
                    ActionBar.placement: ActionBarPlacement.OnBar
                    onTriggered: {
                        settingsSheet.close();
                    }
                }
            ]
            }
        }
    ]
    
    onCreationCompleted: {
        OrientationSupport.supportedDisplayOrientation = 
        SupportedDisplayOrientation.DisplayLandscape;
        OrientationSupport.requestDisplayDirection(DisplayDirection.West);
        
    }
    
}
