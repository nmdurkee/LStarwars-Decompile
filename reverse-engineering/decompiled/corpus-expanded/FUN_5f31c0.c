/* Ghidra pseudocode, not original source.
 * ev_120f2dbe0ae7ec1f4fb84f9bb605c17bea6e5ad9085d38dd392f35fbf38da278
 * Entry: 0x5f31c0; label: FUN_005f31c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_005f31c0(int *param_1,uint *param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  size_t sVar4;
  undefined4 uVar5;
  size_t extraout_ECX;
  void *_Dst;
  ulonglong uVar6;
  
  piVar1 = (int *)*param_1;
  if ((0x414e4933 < *piVar1) && (*piVar1 < 0x414e4936)) {
    sVar4 = FUN_005c9ab0(piVar1);
    _Dst = (void *)(*param_2 + 0xf & 0xfffffff0);
    *param_2 = (*param_2 + 0xf & 0xfffffff0) + sVar4;
    *param_1 = (int)_Dst;
    _memcpy(_Dst,piVar1,sVar4);
    FUN_005c9af0(_Dst,(int)_Dst - (int)piVar1);
    return _Dst;
  }
  uVar2 = *param_2;
  *param_2 = uVar2 + 0xf & 0xfffffff0;
  uVar6 = CONCAT44((size_t *)*param_1,uVar2 + 0xf) & 0xfffffffffffffff0;
  sVar4 = *(size_t *)*param_1;
  if ((0x10000 < (int)sVar4) || ((int)sVar4 < 0)) {
    uVar6 = FUN_005c1300();
    sVar4 = extraout_ECX;
  }
  _memcpy((void *)uVar6,(void *)(uVar6 >> 0x20),sVar4);
  piVar1 = (int *)*param_2;
  *param_1 = (int)piVar1;
  *param_2 = *param_2 + *piVar1;
  iVar3 = *param_1;
  uVar5 = FUN_005e91f0(*(undefined4 *)(iVar3 + 8),iVar3 - *(int *)(iVar3 + 4),0,0);
  *(undefined4 *)(*param_1 + 8) = uVar5;
  *(int *)(*param_1 + 4) = *param_1;
  return *(void **)(*param_1 + 8);
}

