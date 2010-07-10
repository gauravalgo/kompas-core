# Author: mosra <mosra@centrum.cz>
pkgname=libmap2x
pkgver=dev
pkgrel=1
pkgdesc="Lightweight library for displaying and managing maps."
arch=('i686' 'x86_64')
url="http://archerfx.cz/blog/map2x.php"
license=('LGPLv3')
makedepends=('cmake')
optdepends=('qt')

build() {
    mkdir -p "$startdir/build"
    cd "$startdir/build/"

    cmake .. \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DBUILD_TESTS=TRUE
    make
}

package() {
  cd "$startdir/build"
  make DESTDIR="$pkgdir/" install
}
