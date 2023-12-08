import {useEffect} from "react";
import './example.scss'
import {Link} from "react-router-dom";



function Example() {
    useEffect(() => {
        var element = document.getElementById("message");
        element.innerText = window.exampleMessage();
    }, []);
    return (
        <>
            <div className="example">
                Congratulations on your successful installation. Happy hacking!
            </div>
            <div className="example" id="message">
            </div>
        </>
    );
}

export default Example