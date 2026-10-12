/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d5770; label: FUN_004d5770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d5770(void)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 *in_EAX;
  int in_ECX;
  
  uVar1 = (&DAT_029899a0)[in_ECX + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[in_ECX >> 1 & 0x7fff];
  *in_EAX = uVar1;
  in_EAX[1] = fVar2;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  in_EAX[4] = -fVar2;
  in_EAX[5] = uVar1;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[8] = _DAT_008065e0;
  in_EAX[9] = _DAT_008065e4;
  in_EAX[10] = _DAT_008065e8;
  in_EAX[0xb] = _DAT_008065ec;
  in_EAX[0xc] = _DAT_008065f0;
  in_EAX[0xd] = _DAT_008065f4;
  in_EAX[0xe] = _DAT_008065f8;
  in_EAX[0xf] = _DAT_008065fc;
  return;
}

