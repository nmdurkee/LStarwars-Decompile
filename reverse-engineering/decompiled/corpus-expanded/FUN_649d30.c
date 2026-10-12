/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x649d30; label: FUN_00649d30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00649d30(int param_1)

{
  undefined4 uVar1;
  
  DAT_02920a00 = FUN_00619250(0x46,0x46,0xb4,300,DAT_02912e80,FUN_00649d10,"Debris Scale");
  if ((DAT_02920a00 != 0) && (DAT_02920970 != 0)) {
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00649cf0,0,(float)DAT_008101bc * 10.0,
                         *(undefined4 *)(DAT_02920970 + 0xb8),"Debris Scale");
    FUN_00618e10(DAT_02920a00,uVar1);
    FUN_006279b0(param_1,DAT_02920a00);
    *(int *)(DAT_02920a00 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02920a00 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

