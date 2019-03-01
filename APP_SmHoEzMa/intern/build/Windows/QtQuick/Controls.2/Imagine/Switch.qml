/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Quick Controls 2 module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.11
import QtQuick.Templates 2.4 as T
import QtQuick.Controls.Imagine 2.4
import QtQuick.Controls.Imagine.impl 2.4

T.Switch {
    id: control

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(background ? background.implicitHeight : 0,
                             Math.max(contentItem.implicitHeight,
                                      indicator ? indicator.implicitHeight : 0) + topPadding + bottomPadding)
    baselineOffset: contentItem.y + contentItem.baselineOffset

    spacing: 6 // ###

    topPadding: background ? background.topPadding : 0
    leftPadding: background ? background.leftPadding : 0
    rightPadding: background ? background.rightPadding : 0
    bottomPadding: background ? background.bottomPadding : 0

    indicator: NinePatchImage {
        x: text ? (control.mirrored ? control.width - width - control.rightPadding : control.leftPadding) : control.leftPadding + (control.availableWidth - width) / 2
        y: control.topPadding + (control.availableHeight - height) / 2
        width: Math.max(implicitWidth, handle.leftPadding && handle.rightPadding ? handle.implicitWidth : 2 * handle.implicitWidth)
        height: Math.max(implicitHeight, handle.implicitHeight)

        source: Imagine.url + "switch-indicator"
        NinePatchImageSelector on source {
            states: [
                {"disabled": !control.enabled},
                {"pressed": control.down},
                {"checked": control.checked},
                {"focused": control.visualFocus},
                {"mirrored": control.mirrored},
                {"hovered": control.hovered}
            ]
        }

        property NinePatchImage handle: NinePatchImage {
            readonly property real minPos: parent.leftPadding - leftPadding
            readonly property real maxPos: parent.width - width + rightPadding - parent.rightPadding
            readonly property real dragPos: control.visualPosition * parent.width - (width / 2)

            parent: control.indicator

            x: Math.max(minPos, Math.min(maxPos, control.visualPosition * parent.width - (width / 2)))
            y: (parent.height - ?�F� ����D�?�2 �UA����{B�1=�?t#���D �̷�޴��	���Ԉ҂�g��~6	h�����@`��QU*݀�` oe$0T-L�v�<� ��燛�V� vi:��b� �z��cdz��Z��)���	`T�t��๣����ޠ��8�����|�
�ꐫA@��sW�n�eT`�Y�B��c=������3������}/�s��%�����ҁ�"�����r*�B� ����.t(���?U�\��L�K~�䉢�F��k�@�Am�]i�������U�$ҥ����*��
0$��4P:������h�~��%�H�##��K�^}c;��t@�L����v����C�?7@���:�J���9W ��<h�b��u�ރ�����!��~�\������|l��_�"�;U
����^�����EW���p�+@-詺v魗��A� �����e4����̥����:#��+S���"��]�JC��t���Aio�JpF�L��s8b��똮F?��%:���;pt����?
1�.Bw<���Z}�F" �XS�iAV��zj�?��
��%�C܁*PP 䐃�|�d��ǃ�d��^����R��i��SI ��
頟���i����G!9H���kѵxXHHV�U����'V��D~N�t*r|�Ҁ-����ʭ�f" 9	�@�� ��ԏ��op�7�X��* �!�,��Rw����͔�a�gJ�Q���c�����'Ք�LM�� �����؟i�bK2J���X=�\�ʪ �Հ�<�I�#	}�3�ӭ��?J\6����ai�16� m�k�5o�_W�����N2`-H�
@Iᛐ��."���H��.D���'���_�W�4/2q�����o��L"���]'`������WU�����d\�|�^	�/��@����zca�9J��(��z�L����KS���& ߮B��~/W�����O�zQ�b(|/gP�!�9'���E�tf���K��/�C��#Uo�On��s�6@����u�n�?����```�E��%l�$����>"0 �s	�����P�x�G5�v%�3��_�ؚ~�҂��}��o��o* �@t� ]D�j�m��l*�Q��X����lF,����g[����4G:��a[�(�몀 W ��^����1M>����m>j���_
6�X�OX���kj��L�1P�6_75^�?nvYkA��.���/A�Y�D��?l�?�3��'���A��9�� PY���/�k��}uU �}�`W�z��q.6�� ��W���t��m|��i�GG�t�����i��D #T�>��=p�T���O�'���%t� G�>~>2��VςB�#�h����Z�.�.��q���o?y�?��;��w�;��oj�o���w���U����>>��7�����O�_/�ws��Zq|��q�8>ٲ��~����>�;<8�\��!�+�����X�8H��j��c�z�}��~mx]��~�{�?O��?�W<��W��{����>��{�J�mp/�ѿ�����𤏝� �H#�]���F� �H#�D i��F"�4�H#@i�� �4�H�Fi$H#�4��F