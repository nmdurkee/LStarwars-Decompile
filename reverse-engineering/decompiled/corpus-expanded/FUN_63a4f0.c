/* Ghidra pseudocode, not original source.
 * ev_8263a5d3e8c49c8909e3cfceaf1282da1bb42b3174c131367c36677ef6ae0531
 * Entry: 0x63a4f0; label: FUN_0063a4f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063a4f0(int param_1)

{
  undefined4 uVar1;
  
  DAT_02913968 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,FUN_0063a4d0,"Transitions");
  if ((DAT_0291396c != 0) && (DAT_02913968 != 0)) {
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_0063a410,0x3c23d70a,0x409fae14,
                         *(undefined4 *)(DAT_0291396c + 0xb8),"Normal Rate");
    FUN_00618e10(DAT_02913968,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_0063a430,0x3c23d70a,0x409fae14,
                         *(undefined4 *)(DAT_0291396c + 0xbc),"Overshoot Rate");
    FUN_00618e10(DAT_02913968,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_0063a450,0,0x40000000,
                         *(undefined4 *)(DAT_0291396c + 0xc0),"Overshoot Cutin");
    FUN_00618e10(DAT_02913968,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_0063a470,0,0x40000000,
                         *(undefined4 *)(DAT_0291396c + 0xc4),"Overshoot Amount");
    FUN_00618e10(DAT_02913968,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_0063a490,0,0x40000000,
                         *(undefined4 *)(DAT_0291396c + 200),"edrtl_edit_burnset->Overbright Cap");
    FUN_00618e10(DAT_02913968,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_0063a4b0,0,0x40000000,
                         *(undefined4 *)(DAT_0291396c + 0xcc),"edrtl_edit_burnset->Overdark Cap");
    FUN_00618e10(DAT_02913968,uVar1);
    FUN_006279b0(param_1,DAT_02913968);
    *(int *)(DAT_02913968 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02913968 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

