/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x504c90; label: FUN_00504c90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_00504c90(int param_1,int param_2,int param_3,int *param_4,undefined4 param_5,int param_6)

{
  int *piVar1;
  int *piVar2;
  int *_Dst;
  int iVar3;
  int iVar4;
  
  _Dst = (int *)0x0;
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    _Dst = (int *)(*param_4 + 0xfU & 0xfffffff0);
    *param_4 = (int)(_Dst + 0xf);
    _memset(_Dst,0,0x3c);
    _Dst[1] = 0;
    if (param_6 == 0) {
      *_Dst = (int)DAT_009212dc;
      piVar1 = _Dst;
      piVar2 = DAT_00921324;
      if (DAT_009212dc != (int *)0x0) {
        DAT_009212dc[1] = (int)_Dst;
        piVar2 = DAT_00921324;
      }
    }
    else {
      *_Dst = (int)DAT_00921324;
      piVar1 = DAT_009212dc;
      piVar2 = _Dst;
      if (DAT_00921324 != (int *)0x0) {
        DAT_00921324[1] = (int)_Dst;
        piVar1 = DAT_009212dc;
      }
    }
    DAT_00921324 = piVar2;
    DAT_009212dc = piVar1;
    _Dst[4] = param_2;
    _Dst[2] = param_1;
    _Dst[5] = param_3;
    _Dst[3] = *param_4;
    *param_4 = *param_4 + *(int *)(param_1 + 8) * 4;
    _memset((void *)_Dst[3],0,*(int *)(param_1 + 8) * 4);
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 8)) {
      iVar4 = 0;
      do {
        *(undefined1 *)(_Dst[3] + 2 + iVar3 * 4) =
             *(undefined1 *)(*(int *)(param_1 + 0xc) + 10 + iVar4);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x34;
      } while (iVar3 < *(int *)(param_1 + 8));
    }
  }
  return _Dst;
}

