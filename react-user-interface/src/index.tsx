import * as React from 'react';
import {createRoot} from 'react-dom/client';
import {
    createBrowserRouter,
    RouterProvider,
} from 'react-router-dom';
import NotFound from "./built-in/pages/not-found/NotFound";
import Layout from "./built-in/layout";
import Main from "./pages/main/main";

const router = createBrowserRouter([
    {
        element: <Layout/>,
        errorElement: <NotFound/>,
        children: [
            {
                path: '/',
                element: <Main/>
            }
        ]
    }
]);

const root = document.getElementById('root');
if (root != null) {
    createRoot(root).render(
        <RouterProvider router={router}/>
    );
}
