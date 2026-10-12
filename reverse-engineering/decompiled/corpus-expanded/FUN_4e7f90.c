/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e7f90; label: FUN_004e7f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e7f90(void)

{
  uint *puVar1;
  uint uVar2;
  
  if ((DAT_00951b50 == 0) && (DAT_0087a9e0 != 0)) {
    puVar1 = (uint *)(DAT_0087a9e0 + DAT_0087a950 * 4);
    *puVar1 = *puVar1 & ~(DAT_00950d5c | DAT_00950d68 | 0x80000000);
    if (((DAT_0087a90c != 0) &&
        ((*(int *)(*(int *)(DAT_0087a90c + 0x34) + 0xc) != 0 &&
         (*(float *)(DAT_0093d810 + 0x88) < -20.0)))) ||
       (uVar2 = 0, *(float *)(DAT_0093d810 + 0x88) < -21.0)) {
      uVar2 = DAT_00950d68;
    }
    if ((DAT_0087a908 != 0) && (*(int *)(*(int *)(DAT_0087a908 + 0x34) + 0xc) != 0)) {
      uVar2 = uVar2 | DAT_00950d5c;
    }
    if (uVar2 == 0) {
      uVar2 = 0x80000000;
    }
    puVar1 = (uint *)(DAT_0087a9e0 + DAT_0087a950 * 4);
    *puVar1 = *puVar1 | uVar2;
  }
  return;
}

