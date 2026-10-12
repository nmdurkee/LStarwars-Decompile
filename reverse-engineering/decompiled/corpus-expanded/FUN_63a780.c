/* Ghidra pseudocode, not original source.
 * ev_8263a5d3e8c49c8909e3cfceaf1282da1bb42b3174c131367c36677ef6ae0531
 * Entry: 0x63a780; label: FUN_0063a780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063a780(int param_1)

{
  undefined4 uVar1;
  
  DAT_02913960 = FUN_00619250(0x46,0x46,0xdc,300,DAT_02912e80,FUN_0063a760,"Radius Defaults");
  if ((DAT_0291396c != 0) && (DAT_02913960 != 0)) {
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_0063a720,0x3e4ccccd,0x419e6666,
                         *(undefined4 *)(DAT_0291396c + 0x558),"Radius");
    FUN_00618e10(DAT_02913960,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_0063a740,0,0x41200000,
                         *(undefined4 *)(DAT_0291396c + 0x55c),"Falloff");
    FUN_00618e10(DAT_02913960,uVar1);
    FUN_006279b0(param_1,DAT_02913960);
    *(int *)(DAT_02913960 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02913960 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

