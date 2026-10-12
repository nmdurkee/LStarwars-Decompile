/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x560b60; label: FUN_00560b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00560b60(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *_Dst;
  float local_128;
  float local_124;
  int local_120;
  float local_11c;
  int local_118 [69];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_128;
  local_11c = 1e+06;
  iVar4 = 0;
  local_120 = 0;
  iVar3 = -1;
  iVar2 = DAT_009505c0;
  do {
    _Dst = &DAT_00947bc0 + iVar2 * 0x45;
    if ((&DAT_00947cb8)[iVar2 * 0x114] == '\0') goto LAB_00560cad;
    if (((&DAT_00947c98)[iVar2 * 0x45] & 0x1000) == 0) {
      if ((&DAT_00947cba)[iVar2 * 0x114] == '\0') {
        local_124 = (float)(&DAT_00947c80)[iVar2 * 0x45];
        if (((float)(&DAT_00947c7c)[iVar2 * 0x45] == 0.0) || (local_124 == 0.0)) {
          local_128 = 0.0;
        }
        else {
          local_128 = (float)(&DAT_00947c7c)[iVar2 * 0x45] / local_124;
        }
      }
      else {
        local_128 = 1.0;
      }
      if ((iVar3 == -1) || (local_11c < local_128)) {
        local_11c = local_128;
        iVar3 = iVar2;
      }
    }
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x80) {
      iVar2 = 0;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x80);
  if ((iVar3 == -1) && (iVar3 = DAT_009505c0, *(char *)((int)param_1 + 0x4d) != '\0')) {
    _Dst = local_118;
    _memset(_Dst,0,0x114);
    local_120 = 1;
    iVar2 = DAT_009505c0;
  }
  else {
    DAT_009505c0 = iVar3;
    _Dst = &DAT_00947bc0 + DAT_009505c0 * 0x45;
    iVar2 = DAT_009505c0;
  }
LAB_00560cad:
  DAT_009505c0 = iVar2;
  if (((((char)_Dst[0x3e] != '\0') && (_Dst[0x37] != 0)) &&
      ((*(char *)((int)_Dst + 0xfd) == '\0' || (*(char *)((int)_Dst + 0xfd) == '\x01')))) &&
     ((code *)_Dst[0x44] != (code *)0x0)) {
    (*(code *)_Dst[0x44])(_Dst);
  }
  *_Dst = 0;
  iVar2 = 0;
  if (param_1[10] == 0) {
    if (*param_1 == 0) goto LAB_00560cfd;
    iVar3 = FUN_004f1ff0(*param_1);
    if ((param_1[6] & 0x2000U) == 0) {
      do {
        iVar4 = iVar2;
        if (iVar3 <= iVar2) break;
        *(undefined1 *)((int)_Dst + iVar2 + 4) = *(undefined1 *)(*param_1 + iVar2);
        iVar2 = iVar2 + 1;
        iVar4 = iVar2;
      } while (iVar2 < 0x77);
      goto joined_r0x00560d57;
    }
    if (iVar3 < 1) goto LAB_00560cfd;
    *_Dst = *param_1;
  }
  else {
    iVar4 = FUN_005cfac0(param_1[10]);
joined_r0x00560d57:
    if (iVar4 == 0) goto LAB_00560cfd;
  }
  iVar3 = 0;
  *(undefined1 *)((int)_Dst + iVar2 + 4) = 0;
  _Dst[0x35] = 0;
  piVar1 = (int *)param_1[1];
  _Dst[0x25] = *piVar1;
  _Dst[0x26] = piVar1[1];
  iVar2 = piVar1[2];
  _Dst[0x27] = iVar2;
  _Dst[0x1f] = _Dst[0x25];
  _Dst[0x20] = _Dst[0x26];
  _Dst[0x21] = iVar2;
  local_124 = (float)param_1[3];
  _Dst[0x2d] = (int)local_124;
  _Dst[0x2b] = (int)local_124;
  _Dst[0x2f] = 0;
  if ((*(byte *)(param_1 + 6) & 0x80) == 0) {
    iVar3 = param_1[7];
  }
  _Dst[0x30] = iVar3;
  *(char *)(_Dst + 0x3d) = (char)param_1[5];
  *(undefined1 *)((int)_Dst + 0xf5) = *(undefined1 *)((int)param_1 + 0x15);
  *(undefined1 *)((int)_Dst + 0xf6) = *(undefined1 *)((int)param_1 + 0x16);
  *(undefined1 *)((int)_Dst + 0xf7) = *(undefined1 *)((int)param_1 + 0x17);
  _Dst[0x36] = param_1[6];
  piVar1 = (int *)param_1[2];
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)param_1[1];
    _Dst[0x22] = *piVar1;
    _Dst[0x23] = piVar1[1];
    _Dst[0x24] = piVar1[2];
  }
  else {
    _Dst[0x22] = *piVar1;
    _Dst[0x23] = piVar1[1];
    _Dst[0x24] = piVar1[2];
  }
  _Dst[0x2c] = param_1[4];
  if ((*(byte *)(_Dst + 0x36) & 1) == 0) {
    _Dst[0x2e] = _Dst[0x2d];
    _Dst[0x28] = _Dst[0x25];
    _Dst[0x29] = _Dst[0x26];
    _Dst[0x2a] = _Dst[0x27];
    *(undefined1 *)((int)_Dst + 0xf9) = 1;
    *(undefined1 *)((int)_Dst + 0xfb) = 0;
  }
  else {
    *(undefined1 *)((int)_Dst + 0xf9) = 0;
  }
  *(undefined1 *)((int)_Dst + 0xfa) = 0;
  *(undefined1 *)(_Dst + 0x3e) = 1;
  *(undefined1 *)(_Dst + 0x3f) = *(undefined1 *)((int)param_1 + 0x4f);
  *(undefined2 *)((int)_Dst + 0xe6) = *(undefined2 *)((int)param_1 + 0x26);
  piVar1 = (int *)param_1[10];
  if (piVar1 == (int *)0x0) {
    iVar2 = 0;
    _Dst[0x3a] = 0;
    _Dst[0x3b] = 0;
  }
  else {
    _Dst[0x3a] = *piVar1;
    _Dst[0x3b] = piVar1[1];
    iVar2 = piVar1[2];
  }
  _Dst[0x3c] = iVar2;
  *(char *)((int)_Dst + 0xfd) = (char)param_1[0x13];
  _Dst[0x37] = param_1[0xb];
  _Dst[0x31] = param_1[0xc];
  iVar2 = param_1[0xd];
  *(undefined2 *)(_Dst + 0x38) = 0;
  _Dst[0x32] = iVar2;
  *(undefined2 *)((int)_Dst + 0xe2) = 0;
  *(undefined2 *)(_Dst + 0x39) = 0;
  _Dst[0x40] = param_1[0xe];
  _Dst[0x41] = param_1[0xf];
  _Dst[0x42] = param_1[0x10];
  _Dst[0x44] = param_1[0x12];
  _Dst[0x43] = param_1[0x11];
  *(undefined1 *)((int)_Dst + 0xff) = *(undefined1 *)((int)param_1 + 0x4d);
  *(undefined1 *)((int)_Dst + 0xfe) = *(undefined1 *)((int)param_1 + 0x4e);
  _Dst[0x34] = param_1[8];
  _Dst[0x33] = 0x3f800000;
  if ((local_120 != 0) && ((code *)_Dst[0x44] != (code *)0x0)) {
    (*(code *)_Dst[0x44])(_Dst);
  }
LAB_00560cfd:
  __security_check_cookie(local_4 ^ (uint)&local_128);
  return;
}

