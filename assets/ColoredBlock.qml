import bb.cascades 1.2

Container {    
    layout: DockLayout {}
    verticalAlignment: VerticalAlignment.Fill
    horizontalAlignment: HorizontalAlignment.Fill
    preferredHeight: 150
    rightPadding: 30
    leftPadding: 30
    
    property variant backgroundColor: Color.Black
    
    
    Container {
        background: backgroundColor
        horizontalAlignment: HorizontalAlignment.Fill
        translationY: 14
        maxHeight: 145
        
        Container {       
            minHeight: 725
            minWidth: 594     
            opacity: 0
            
            
        }
        Container {       
            
        animations: [
            TranslateTransition {
                id: showSlideAnimation
                fromY: 30
                toY: 0
                easingCurve: StockCurve.ExponentialOut
                duration: 800       
            },
            TranslateTransition {
                id: hideSlideAnimation
                fromY: 0
                toY: 30
                easingCurve: StockCurve.ExponentialOut
                duration: 250       
            }   
        ]
}
    }
}