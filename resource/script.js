/* ==== show mobile menu ==== */
const showMenu = (toggleId, navId) => {
    const toggle = document.getElementById(toggleId);
    const nav = document.getElementById(navId);

    if (toggle && nav) {
        toggle.addEventListener('click', () => {
            nav.classList.toggle('show-menu');
        })
    }
}

showMenu('nav-toggle','nav-menu');


/* ==== remove mobile menu ==== */
const navLink = document.querySelectorAll('.nav_link');

function clickLink() {
    const navMenu = document.getElementById('nav-menu');
    navMenu.classList.remove('show-menu');
}

navLink.forEach(items => items.addEventListener('click', clickLink));


/* ==== scroll section active link ==== */
const sections = document.querySelectorAll('section[id]');

function scrollActive() {
    const scrollY = window.pageYOffset;

    sections.forEach(current => {
        const sectionHeight = current.offsetHeight;
        const sectionTop = current.offsetTop - 50;
        var sectionsId = current.getAttribute('id');

        if (scrollY > sectionTop && scrollY <= sectionTop + sectionHeight) {
            document.querySelector('.nav_menu a[href*=' + sectionsId + ']').classList.add('active-link');
        }
        else {
            document.querySelector('.nav_menu a[href*=' + sectionsId + ']').classList.remove('active-link');
        }
    })
}

window.addEventListener('scroll', scrollActive);


/* ==== change background header ==== */
function scrollHeader() {
    const header = document.getElementById('header');
    if(this.scrollY >= 200) {
        header.classList.add('scroll-header');
    }
    else {
        header.classList.remove('scroll-header');
    }
}

window.addEventListener('scroll', scrollHeader);


/* ==== show scroll top ==== */
function scrollTop() {
    const scrollTop = document.getElementById('scroll-top');
    if(this.scrollY >= 560) {
        scrollTop.classList.add('show-scroll');
    }
    else {
        scrollTop.classList.remove('scroll-scroll');
    }
}

window.addEventListener('scroll', scrollTop);
