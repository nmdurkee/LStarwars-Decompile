/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x441c00; label: FUN_00441c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441c00(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;
  
  if (((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
     (iVar1 = **(int **)(param_3 + 0xd0), iVar1 != 0)) {
    FUN_005b3800(&local_c,iVar1 + 0x80,PTR_DAT_008021b4 + 0x11c);
    if (*(float *)(PTR_DAT_008021b4 + 0x118) * local_4 +
        *(float *)(PTR_DAT_008021b4 + 0x110) * local_c +
        *(float *)(PTR_DAT_008021b4 + 0x114) * local_8 < 0.0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

