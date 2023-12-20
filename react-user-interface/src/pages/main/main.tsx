import * as React from "react"
import "../../cpp-window"
import "./main.scss"

const Main: React.FC = () => {

    return (
        <div className="container">
            <div className="container__title">
                {window.exampleMessage()}
            </div>
        </div>
    )
}

export default Main;