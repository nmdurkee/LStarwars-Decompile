/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d70f0; label: FUN_004d70f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d70f0(int param_1,undefined4 param_2)

{
  int in_EAX;
  undefined2 in_DX;
  uint uVar1;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  if (*(char *)(*(int *)(param_1 + 0x2ac0) + 0xe + in_EAX * 0x10) != '\0') {
    uVar1 = (uint)(unaff_ESI != 0);
    FUN_005b4670(local_40,in_DX);
    FUN_005b5160(local_40,*(undefined2 *)(unaff_EDI + 0x78 + uVar1 * 2));
    FUN_005b4cf0(local_40,*(undefined2 *)(unaff_EDI + 0x74 + uVar1 * 2));
    local_4c = *(undefined4 *)(unaff_EDI + 0x10 + unaff_ESI * 0xc);
    local_48 = *(undefined4 *)(unaff_EDI + 0x6c + uVar1 * 4);
    local_44 = *(undefined4 *)(unaff_EDI + (unaff_ESI * 3 + 6) * 4);
    FUN_005b4900(local_40,&local_4c);
    FUN_005ff7a0(*(int *)(param_1 + 0x2ac0) + in_EAX * 0x10,local_40,param_2);
  }
  return;
}

