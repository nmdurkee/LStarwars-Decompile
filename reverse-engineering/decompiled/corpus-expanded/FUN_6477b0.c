/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x6477b0; label: FUN_006477b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006477b0(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_0291f678 = FUN_00619250(0x46,0x46,0x104,300,DAT_02912e80,FUN_00647790,"Emitter Timing");
    if (DAT_0291f678 != 0) {
      uVar1 = FUN_00627bc0(0x400000,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 0x16 & 1,1,
                           FUN_006476e0,"Trigger effect inside cutoff");
      FUN_00618e10(DAT_0291f678,uVar1);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00647710,0x3c23d70a,(float)DAT_008101bc * 5.0,
                           *(undefined4 *)(DAT_02920970 + 0xec),"On Time");
      FUN_00618e10(DAT_0291f678,uVar1);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00647730,0,(float)DAT_008101bc * 5.0,
                           *(undefined4 *)(DAT_02920970 + 0xf0),"Random On Time");
      FUN_00618e10(DAT_0291f678,uVar1);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00647750,0,(float)DAT_008101bc * 5.0,
                           *(undefined4 *)(DAT_02920970 + 0xf4),"Off Time");
      FUN_00618e10(DAT_0291f678,uVar1);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00647770,0,(float)DAT_008101bc * 5.0,
                           *(undefined4 *)(DAT_02920970 + 0xf8),"Random Off Time");
      FUN_00618e10(DAT_0291f678,uVar1);
      FUN_006279b0(param_1,DAT_0291f678);
      *(int *)(DAT_0291f678 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_0291f678 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

