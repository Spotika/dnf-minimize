import * as React from "react";
import {HelmetProvider} from "react-helmet-async";
import {Outlet} from "react-router-dom"
import {useEffect} from "react";
import "../cpp-window";
import "./clear_styles.scss"

const Layout: React.FC = () => {
    useEffect(() => {
        window.checkBrowserView(); // For control access to app
    }, []);
    return (
        <>
            <HelmetProvider>
                <Outlet/>
            </HelmetProvider>
        </>
    )
};

export default Layout;