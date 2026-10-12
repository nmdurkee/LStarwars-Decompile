/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x6668e0; label: FUN_006668e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006668e0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    DAT_02947c6c = FUN_00619250(0x46,0x46,200,0xfa,DAT_02912e80,FUN_006668c0,"Damage Flags");
    if (DAT_02947c6c != 0) {
      uVar2 = FUN_00627bc0(1,&DAT_008109d8,*(byte *)(iVar1 + 0x2f2) & 1,1,FUN_00666860,&DAT_0076dd58
                          );
      FUN_00618e10(DAT_02947c6c,uVar2);
      uVar2 = FUN_00627bc0(2,&DAT_008109d8,*(byte *)(iVar1 + 0x2f2) >> 1 & 1,2,FUN_00666860,
                           &DAT_0076dd50);
      FUN_00618e10(DAT_02947c6c,uVar2);
    }
    FUN_006279b0(param_1,DAT_02947c6c);
    *(int *)(DAT_02947c6c + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02947c6c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

