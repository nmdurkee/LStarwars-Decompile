/* Ghidra pseudocode, not original source.
 * ev_277e9292cb53e7665c3bde753cc9c2d26e6793a349ba78c22fc7a8e115ea3a32
 * Entry: 0x664850; label: FUN_00664850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00664850(int param_1)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  DAT_02962a80 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_00664830,"Orphan List");
  if (DAT_02962a80 != 0) {
    puVar2 = &DAT_02924b74;
    do {
      if (*(int *)(puVar2 + -0x18) == -1) {
        uVar1 = FUN_00627a80(0,&DAT_008109d8,0,0,0,puVar2);
        FUN_00618e10(DAT_02962a80,uVar1);
        *(undefined1 *)(DAT_02900c84 + 0x12) = 0x10;
      }
      puVar2 = puVar2 + 0x58;
    } while ((int)puVar2 < 0x292fb74);
    FUN_006279b0(param_1,DAT_02962a80);
    *(int *)(DAT_02962a80 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02962a80 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

