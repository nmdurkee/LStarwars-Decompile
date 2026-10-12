/* Ghidra pseudocode, not original source.
 * ev_b6e394b5e6447b25b30eeb5758ac1a35d86131e46c625f62ba009b62f4fc19bf
 * Entry: 0x538c10; label: FUN_00538c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00538c10(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(DAT_009238e4 + 0x4868);
  if ((*(int *)(iVar1 + 0x20) != 0) && (*(int *)(iVar1 + 0x20) == *(int *)(iVar1 + 0x24))) {
    iVar1 = FUN_00619250(200,0x46,0xf0,0x10e,DAT_02912e80,&LAB_00533700,"Delete current path node??"
                        );
    if (iVar1 != 0) {
      uVar2 = FUN_00627a80(0,&DAT_00801cb4,0,0,FUN_00533670,&DAT_0075f2d0);
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00533670,&PTR_DAT_0075f2d4);
      FUN_00618e10(iVar1,uVar2);
      return iVar1;
    }
  }
  return 0;
}

