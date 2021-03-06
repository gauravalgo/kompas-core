Name: kompas-core
URL: http://mosra.cz/blog/kompas.php
Version: 0.1.2
Release: 1
License: LGPLv3
%if %{defined suse_version}
Group: System/Libraries
%else
Group: System Environment/Libraries
%endif
Source: https://github.com/mosra/%{name}/tarball/v%{version}/%{name}-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-buildroot
BuildRequires: gcc-c++
BuildRequires: cmake >= 2.6.0
BuildRequires: corrade-devel
Requires: corrade

Summary: Core library for Kompas navigation software

%description
Core interfaces and plugin management for Kompas.

%package devel
%if %{defined suse_version}
Group: Development/Libraries/C and C++
%else
Group: Development/Libraries
%endif
Summary: Kompas Core development files
Requires: %{name} = %{version}
Requires: corrade-devel

%description devel
Core headers and tools needed for developing for Kompas.

%prep
%setup -q -n mosra-kompas-core-6f5eaea

%build
mkdir build && cd build
cmake .. \
    -DCMAKE_INSTALL_PREFIX=%{_prefix} \
    -DCMAKE_BUILD_TYPE=Release
make %{?_smp_mflags}

%install
rm -rf $RPM_BUILD_ROOT
cd build
make DESTDIR=$RPM_BUILD_ROOT install
strip $RPM_BUILD_ROOT/%{_prefix}/lib*/* $RPM_BUILD_ROOT/%{_prefix}/bin/*

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)
%{_prefix}/lib*/*.so.*
%doc COPYING COPYING.LESSER

%files devel
%defattr(-,root,root,-)
%{_prefix}/include/Kompas
%{_prefix}/share/*/Modules
%{_prefix}/lib*/*.so
%doc COPYING COPYING.LESSER

%changelog
* Sun Mar 20 2011 Vladimír Vondruš <mosra@centrum.cz> - 0.1.2-1
- New upstream version 0.1.2.

* Sat Feb 26 2011 Vladimír Vondruš <mosra@centrum.cz> - 0.1.1-1
- Initial release.
