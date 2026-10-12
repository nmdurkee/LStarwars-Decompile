/* Ghidra analysis pseudocode, not original source.
 * ev_0d221f2c9357ed308f9b597510bd130964f67481868d3ff45e1443ef5eb3d7b9
 * Entry: 0x624590; label: FUN_00624590
 */

undefined4 FUN_00624590(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  if ((*(byte *)(param_4 + 0x78) & 0x40) != 0) {
    FUN_006193e0(param_1,param_2);
    if (*(code **)(param_2 + 0x4c) != (code *)0x0) {
      (**(code **)(param_2 + 0x4c))(param_1,param_2,*(undefined4 *)(param_4 + 0x70));
    }
    return 0;
  }
  if ((*(uint *)(param_4 + 0x70) & 0x40) != 0) {
    if (*(code **)(param_2 + 0x50) != (code *)0x0) {
      (**(code **)(param_2 + 0x50))(param_1,param_2,*(uint *)(param_4 + 0x70));
    }
  }
  return 0;
}

