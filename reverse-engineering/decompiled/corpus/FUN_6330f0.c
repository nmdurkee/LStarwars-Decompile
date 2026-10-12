/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x6330f0; label: FUN_006330f0
 */

undefined4 * FUN_006330f0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 *_Dst;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  _Dst = _malloc(0x50);
  if (_Dst == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  _memset(_Dst,0,0x50);
  if (param_4 == 0) {
    uVar4 = *(undefined4 *)(param_1 + 0x18);
  }
  else {
    uVar4 = *(undefined4 *)(param_1 + 0x14);
  }
  uVar1 = *(undefined4 *)(param_1 + 4);
  *_Dst = uVar1;
  _Dst[5] = param_2;
  _Dst[6] = param_3;
  _Dst[3] = param_4;
  _Dst[4] = uVar4;
  if (param_4 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x20);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x1c);
  }
  _Dst[2] = uVar2;
  if (param_4 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x10);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0xc);
  }
  _Dst[1] = uVar2;
  _Dst[7] = 0;
  iVar3 = FUN_006322e0(uVar1,uVar2,_Dst[9],uVar4,param_2,param_3);
  _Dst[0x13] = iVar3;
  if (iVar3 == 0) {
    _free(_Dst);
    _Dst = (undefined4 *)0x0;
  }
  _Dst[8] = 1;
  return _Dst;
}

