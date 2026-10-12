/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4bda50; label: FUN_004bda50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004bda50(int param_1)

{
  int iVar1;
  undefined4 in_EAX;
  int unaff_ESI;
  float10 fVar2;
  
  *(uint *)(unaff_ESI + 0x7bc) = *(uint *)(unaff_ESI + 0x7bc) & 0xffffffbf;
  *(undefined4 *)(unaff_ESI + 0x77c) = 0;
  *(undefined1 *)(unaff_ESI + 0x7b5) = 0x5c;
  *(undefined4 *)(unaff_ESI + 0x798) = in_EAX;
  *(undefined2 *)(unaff_ESI + 0x7aa) = 0xad;
  fVar2 = (float10)FUN_0062e040((int)*(short *)(unaff_ESI + 0x1064),0xad,0,0,1);
  *(float *)(unaff_ESI + 0x784) = (float)fVar2;
  if ((float)fVar2 <= 0.0) {
    *(undefined4 *)(unaff_ESI + 0x784) = 0x3f800000;
  }
  *(uint *)(unaff_ESI + 0x7bc) = *(uint *)(unaff_ESI + 0x7bc) | 0x20;
  iVar1 = *(int *)(unaff_ESI + 0x798);
  if (param_1 != 0) {
    *(short *)(unaff_ESI + 0x5a) = *(short *)(iVar1 + 0xa0) + -0x8000;
    *(undefined1 *)(iVar1 + 0xa3) = 1;
    return;
  }
  *(undefined2 *)(unaff_ESI + 0x5a) = *(undefined2 *)(iVar1 + 0xa0);
  return;
}

