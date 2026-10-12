/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x505cf0; label: FUN_00505cf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_00505cf0(int *param_1,int param_2,int param_3,undefined4 param_4,int *param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *_Dst;
  
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  _Dst = (int *)(*param_5 + 0xfU & 0xfffffff0);
  *param_5 = (int)(_Dst + 0x3e);
  if (_Dst == (int *)0x0) {
    return (int *)0x0;
  }
  _memset(_Dst,0,0xf8);
  _Dst[0x3a] = 0x3f800000;
  _Dst[0x31] = param_2;
  _Dst[0x32] = param_3;
  *(undefined1 *)((int)_Dst + 0xdf) = 0;
  if (1 < *param_1) {
    if ((*(byte *)(param_1 + 0xe) & 1) != 0) {
      _Dst[0x2f] = param_1[0xc];
      _Dst[0x30] = param_1[0xd];
      iVar1 = param_1[0xd];
      _Dst[0x22] = _Dst[0x22] & 0xefffffff;
      _Dst[0x3b] = iVar1;
      *(undefined1 *)((int)_Dst + 0xdf) = 0;
    }
    if ((1 < *param_1) && ((*(byte *)(param_1 + 0xe) & 9) != 0)) {
      _Dst[0x22] = _Dst[0x22] | 0x20000000;
      goto LAB_00505daa;
    }
  }
  _Dst[0x22] = _Dst[0x22] & 0xdfffffff;
LAB_00505daa:
  FUN_00505bd0(_Dst,param_1,param_2,param_3,0);
  (*(code *)PTR_FUN_00800820)();
  if (param_6 == 0) {
    *_Dst = (int)DAT_0092133c;
    piVar2 = DAT_009212d8;
    piVar3 = _Dst;
    if (DAT_0092133c != (int *)0x0) {
      DAT_0092133c[1] = (int)_Dst;
      piVar2 = DAT_009212d8;
    }
  }
  else {
    *_Dst = (int)DAT_009212d8;
    piVar2 = _Dst;
    piVar3 = DAT_0092133c;
    if (DAT_009212d8 != (int *)0x0) {
      DAT_009212d8[1] = (int)_Dst;
      piVar3 = DAT_0092133c;
    }
  }
  DAT_0092133c = piVar3;
  DAT_009212d8 = piVar2;
  _Dst[0x3c] = *param_5 - (int)_Dst;
  (*(code *)PTR_FUN_00800824)();
  return _Dst;
}

