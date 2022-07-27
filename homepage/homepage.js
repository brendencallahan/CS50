// Add list item
document.querySelector('#form').addEventListener('submit', function (e) {
    // Prevent reloading page
    e.preventDefault();

    // Convert user's string input into text node for DOM
    const text = document.querySelector('#todo').value;
    const textNode = document.createTextNode(text);

    // Get reference elements
    const list = document.querySelector('#list');
    const item = document.querySelector('#item');

    // Create empty list then append converted user input
    const newItem = document.createElement('li');
    newItem.appendChild(textNode);

    // Add new list item to list
    list.appendChild(newItem, item);
});