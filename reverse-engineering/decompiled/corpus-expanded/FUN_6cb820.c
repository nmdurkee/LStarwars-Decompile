/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6cb820; label: FUN_006cb820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006cb820(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  char *pcStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  char *pcStack_10;
  
  *(int *)(in_ECX + 0xa4c) = *(int *)(in_ECX + 0xa4c) + 1;
  pcStack_10 = "FileInfo";
  uStack_14 = 0x6cb844;
  (**(code **)(*param_1 + 0x18))();
  uStack_14 = 1;
  uStack_18 = 4;
  pcStack_20 = (char *)0x6cb852;
  iStack_1c = in_ECX + 0xa4c;
  (**(code **)(*param_1 + 8))();
  pcStack_20 = (char *)0x6cb85b;
  (**(code **)(*param_1 + 0x1c))();
  pcStack_20 = "Settings";
  uStack_24 = 0x6cb869;
  (**(code **)(*param_1 + 0x18))();
  uStack_24 = 1;
  uStack_28 = 4;
  iStack_2c = in_ECX + 0x10a0;
  (**(code **)(*param_1 + 8))();
  (**(code **)(*param_1 + 8))(in_ECX + 0x10a4,4,1);
  (**(code **)(*param_1 + 0x1c))();
  (**(code **)(*param_1 + 0x18))("Editors");
  iStack_2c = *(int *)(in_ECX + 0x944);
  (**(code **)(*param_1 + 8))(&iStack_2c,4,1);
  for (piVar1 = *(int **)(in_ECX + 0x93c); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    iVar2 = *param_1;
    uVar3 = (**(code **)(*piVar1 + 8))();
    (**(code **)(iVar2 + 0x18))(uVar3);
    (**(code **)(*piVar1 + 0x14))(param_1);
    (**(code **)(*param_1 + 0x1c))();
  }
  (**(code **)(*param_1 + 0x1c))();
  return 1;
}

