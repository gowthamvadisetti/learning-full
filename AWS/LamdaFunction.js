exports.handler = async (event) => {
    
    let name = JSON.stringify(`Hello from the other side, ${event.firstName} ${event.lastName}`);
    const response = {
        statusCode: 200,
        body: name
    };
    return response;
};