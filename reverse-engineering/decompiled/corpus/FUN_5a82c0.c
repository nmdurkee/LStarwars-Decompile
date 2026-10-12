/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a82c0; label: FUN_005a82c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a82c0(int param_1,int param_2)

{
  float local_c;
  float local_8;
  float local_4;
  
  if ((*(uint *)(*(int *)(param_1 + 0x128) + 100) & 0x4000) != 0) {
    local_c = *(float *)(PTR_DAT_008021b4 + 0x11c) + *(float *)(PTR_DAT_008021b4 + 0x110) * 2.0;
    local_8 = *(float *)(PTR_DAT_008021b4 + 0x114) * 2.0 + *(float *)(PTR_DAT_008021b4 + 0x120);
    local_4 = *(float *)(PTR_DAT_008021b4 + 0x118) * 2.0 + *(float *)(PTR_DAT_008021b4 + 0x124);
    FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x134) + 8) + param_2 * 0x14),&local_c,
                 0x3c,_DAT_00925018,0,0,0);
  }
  return;
}

