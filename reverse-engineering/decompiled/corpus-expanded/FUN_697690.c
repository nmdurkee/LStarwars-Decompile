/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x697690; label: FUN_00697690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00697690(int param_1)

{
  undefined4 *_Dst;
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = param_1 * 0x34 + in_ECX;
  _Dst = (undefined4 *)(iVar1 + 0xc);
  if (*(int *)(iVar1 + 0xc) != 0) {
    piVar2 = *(int **)(iVar1 + 0x10);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    (**(code **)(*(int *)*_Dst + 0x48))((int *)*_Dst);
    (**(code **)(*(int *)*_Dst + 8))((int *)*_Dst);
    *_Dst = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(int *)(in_ECX + 0xd10) = *(int *)(in_ECX + 0xd10) + -1;
  }
  _memset(_Dst,0,0x34);
  return;
}

