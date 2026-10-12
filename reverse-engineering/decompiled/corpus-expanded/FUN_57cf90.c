/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57cf90; label: FUN_0057cf90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057cf90(void)

{
  int iVar1;
  int in_stack_00000010;
  undefined4 in_stack_00000014;
  int in_stack_00000018;
  undefined1 local_58 [24];
  undefined1 local_40 [64];
  
  FUN_005c9c40(*(undefined4 *)(in_stack_00000010 + 0x50),in_stack_00000014,local_58);
  iVar1 = FUN_005010f0(in_stack_00000010,in_stack_00000014,local_58,0,0);
  if (iVar1 != 0) {
    FUN_00500e50(in_stack_00000010,in_stack_00000014,local_40,local_58);
    if ((*(byte *)(in_stack_00000010 + 0x58) & 4) != 0) {
      FUN_005b4960(local_40,in_stack_00000010 + 0x40);
    }
    if (in_stack_00000018 != 0) {
      FUN_005b5430(local_40,local_40,in_stack_00000018);
    }
    FUN_00552bc0(0,(int)*(short *)PTR_DAT_00803e00,local_40);
    FUN_00552bc0(0,(int)*(short *)(PTR_DAT_00803e00 + 2),local_40);
  }
  return;
}

