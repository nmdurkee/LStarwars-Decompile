/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x6322e0; label: FUN_006322e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_006322e0(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                  int param_6)

{
  int iVar1;
  int unaff_EBP;
  void *_Dst;
  int *piStack_30;
  int iStack_2c;
  void *pvStack_28;
  undefined4 *puStack_24;
  undefined4 uStack_20;
  undefined4 local_c [3];
  
  uStack_20 = 0;
  puStack_24 = local_c;
  pvStack_28 = (void *)0x0;
  iStack_2c = param_2;
  piStack_30 = (int *)0x200;
  local_c[0] = 0;
  iVar1 = (**(code **)(*param_1 + 0x5c))(param_1,param_5,param_6,1);
  if (((-1 < iVar1) ||
      (iVar1 = (**(code **)(*param_1 + 0x5c))(param_1,param_5,param_6,1,0,param_2,1,&piStack_30,0),
      -1 < iVar1)) &&
     (iVar1 = (**(code **)(*piStack_30 + 0x4c))(piStack_30,0,&iStack_2c,0,0), -1 < iVar1)) {
    _Dst = pvStack_28;
    for (; param_6 != 0; param_6 = param_6 + -1) {
      _memset(_Dst,0,unaff_EBP * param_5);
      _Dst = (void *)((int)_Dst + iStack_2c);
    }
    (**(code **)(*piStack_30 + 0x50))(piStack_30,0);
  }
  return piStack_30;
}

