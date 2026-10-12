/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d1e10; label: FUN_006d1e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d1e10(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined *puVar4;
  
  iVar1 = FUN_00619250(*(int *)(param_1 + 0x1c) + *(int *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,0);
  if (iVar1 != 0) {
    uVar3 = 0;
    puVar4 = &DAT_02973e9c;
    do {
      if (((uVar3 < 10) && (puVar4 != (undefined *)0x0)) && ((*(uint *)(puVar4 + 0xa4) & 1) != 0)) {
        uVar2 = FUN_00627bc0(uVar3 << 6,&DAT_0081f9a0,
                             (int)(*(uint *)(puVar4 + 0xa4) << 0x1e) >> 0x1f,1,FUN_006c2da0,puVar4);
        FUN_00618e10(iVar1,uVar2);
      }
      puVar4 = puVar4 + 0xa8;
      uVar3 = uVar3 + 1;
    } while ((int)puVar4 < 0x297452c);
    uVar2 = FUN_00626290(0,&DAT_0081f9a0);
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_0081f9a0,0,0,FUN_006d05e0,&DAT_0077017c);
    FUN_00618e10(iVar1,uVar2);
    FUN_006242b0(iVar1,5);
    FUN_00627930(iVar1,1);
    FUN_006279b0(param_1,iVar1);
  }
  return;
}

