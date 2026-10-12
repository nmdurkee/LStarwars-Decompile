/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x432a70; label: FUN_00432a70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00432a70(float param_1)

{
  int unaff_ESI;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *(float *)(unaff_ESI + 0x30) + param_1 * *(float *)(unaff_ESI + 0x80);
  local_8 = *(float *)(unaff_ESI + 0x84) * param_1 + *(float *)(unaff_ESI + 0x34);
  local_4 = param_1 * *(float *)(unaff_ESI + 0x88) + *(float *)(unaff_ESI + 0x38);
  FUN_005b5160();
  *(float *)(unaff_ESI + 0x30) = local_c;
  *(float *)(unaff_ESI + 0x34) = local_8;
  *(float *)(unaff_ESI + 0x38) = local_4;
  FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 2000),&local_c,10,
               _DAT_00925018,0,0,0);
  return;
}

