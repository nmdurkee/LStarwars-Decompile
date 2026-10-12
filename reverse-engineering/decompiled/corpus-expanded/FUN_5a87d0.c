/* Ghidra pseudocode, not original source.
 * ev_724cabe4f5fc1a17992688438315818e84a5f5e3e3395d254642ecf9571b826a
 * Entry: 0x5a87d0; label: FUN_005a87d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a87d0(void)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 *in_EAX;
  int in_ECX;
  
  uVar1 = (&DAT_029899a0)[in_ECX + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[in_ECX >> 1 & 0x7fff];
  *in_EAX = uVar1;
  in_EAX[1] = 0;
  in_EAX[2] = -fVar2;
  in_EAX[3] = 0;
  in_EAX[4] = _DAT_008065d0;
  in_EAX[5] = _DAT_008065d4;
  in_EAX[6] = _DAT_008065d8;
  in_EAX[7] = _DAT_008065dc;
  in_EAX[8] = fVar2;
  in_EAX[9] = 0;
  in_EAX[0xb] = 0;
  in_EAX[10] = uVar1;
  in_EAX[0xc] = _DAT_008065f0;
  in_EAX[0xd] = _DAT_008065f4;
  in_EAX[0xe] = _DAT_008065f8;
  in_EAX[0xf] = _DAT_008065fc;
  return;
}

