/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x432a70; label: FUN_00432a70
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

