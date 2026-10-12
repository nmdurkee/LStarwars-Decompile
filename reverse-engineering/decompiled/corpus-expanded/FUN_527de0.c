/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x527de0; label: FUN_00527de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00527de0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(DAT_009238e4 + 0x4381c) != 0) &&
     (*(int *)(DAT_009238e4 + 0x4381c) == *(int *)(DAT_009238e4 + 0x43820))) {
    iVar1 = FUN_00619250(200,0x46,0xf0,0x10e,DAT_02912e80,FUN_00527d40,"Delete Antinode??");
    if (iVar1 != 0) {
      uVar2 = FUN_00627a80(0,&DAT_00801cb4,0,0,FUN_00527d70,&DAT_0075f2d0);
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00527d70,&PTR_DAT_0075f2d4);
      FUN_00618e10(iVar1,uVar2);
      return iVar1;
    }
  }
  return 0;
}

