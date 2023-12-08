import React from 'react';

const NotFound = () => {
    return (
        <div style={styles.container}>
            <h1 style={styles.heading}>404 - Страница не найдена</h1>
        </div>
    );
};

const styles = {
    container: {
        display: 'flex',
        flexDirection: 'column',
        alignItems: 'center',
        justifyContent: 'center',
        height: '100vh',
    },
    heading: {
        fontSize: '2rem',
        marginBottom: '16px',
    },
    message: {
        fontSize: '1rem',
    },
};

export default NotFound;
