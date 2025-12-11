function toggleMenu() {
    const menu = document.getElementById('menu');
    const line1 = document.getElementById('line1');
    const line2 = document.getElementById('line2');
    const line3 = document.getElementById('line3');
    const backpanel = document.getElementById('backpanel');
    if (menu.style.display === 'flex') {
        menu.style.opacity = '1';
        backpanel.style.opacity = '1';
        setTimeout(() => {
            menu.style.opacity = '0';
            backpanel.style.opacity = '0';
        }, 10);
        setTimeout(() => {
            menu.style.display = 'none';
            backpanel.style.display = 'none';
        }, 300);
        line1.style.transform = 'rotate(0deg)';
        line2.style.opacity = '1';
        line3.style.transform = 'rotate(0deg)';
        
    } else {
        menu.style.display = 'flex';
        menu.style.opacity = '0';
        backpanel.style.display = 'block';
        backpanel.style.opacity = '0';
        setTimeout(() => {
            menu.style.opacity = '1';
            backpanel.style.opacity = '1';
        }, 10);
        line1.style.transform = 'rotate(45deg) translate(5px, 5px)';
        line2.style.opacity = '0';
        line3.style.transform = 'rotate(-45deg) translate(5px, -5px)';
        
    }
}
function closeMenu() {
    const menu = document.getElementById('menu');
    const line1 = document.getElementById('line1');
    const line2 = document.getElementById('line2');
    const line3 = document.getElementById('line3');
    const backpanel = document.getElementById('backpanel');
    menu.style.opacity = '1';
    backpanel.style.opacity = '1';
    setTimeout(() => {
        menu.style.opacity = '0';
        backpanel.style.opacity = '0';
    }, 10);
    setTimeout(() => {
        menu.style.display = 'none';
        backpanel.style.display = 'none';
    }, 300);
    line1.style.transform = 'rotate(0deg)';
    line2.style.opacity = '1';
    line3.style.transform = 'rotate(0deg)';
    
}