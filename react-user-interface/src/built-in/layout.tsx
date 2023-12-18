import * as React from "react";
import {HelmetProvider} from "react-helmet-async";
import {Outlet} from "react-router-dom"
import {useEffect} from "react";
import "../cpp-window";

const Layout: React.FC = () => {
    useEffect(() => {
        window.checkBrowserView();
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