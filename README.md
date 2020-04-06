# libtextclassifier

A library for on-device text classification (address, telephone number,
emails etc.).

# Usage in Chrome OS

To use libtextclassifier, one also needs to install a flatbuffer model defined
in "model.fbs". For simplicity, this model file will be installed in the
[ebuild of ml-service][ml-9999-ebuild].

The [ml-service] is currently the only user of this library. If another library
in Chrome OS also wants to use it, please let the owners of [ml-service] and
libtextclassifier know because then,

1. we need to make libtextclassifier into a shared library to save space;
2. we may also need to move the installation of libtextclassifier's model file
into libtextclassifier's ebuild.


[ml-9999-ebuild]: https://source.chromium.org/chromiumos/chromiumos/codesearch/+/master:src/third_party/chromiumos-overlay/chromeos-base/ml/ml-9999.ebuild
[ml-service]: https://source.chromium.org/chromiumos/chromiumos/codesearch/+/master:src/platform2/ml/;l=1?q=ml%2F&sq=&ss=chromiumos
