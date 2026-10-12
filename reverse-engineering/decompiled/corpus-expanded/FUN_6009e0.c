/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x6009e0; label: FUN_006009e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006009e0(float param_1,float param_2,undefined4 param_3)

{
  float *pfVar1;
  undefined4 *puVar2;
  
  pfVar1 = (float *)*DAT_02854d10;
  *pfVar1 = _DAT_0080e2b0 * param_1 + _DAT_02854d20;
  pfVar1[1] = _DAT_0080e2b4 * param_2 + _DAT_02854d24;
  *(undefined4 *)(*DAT_02854d10 + 8) = param_3;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  if ((DAT_0080e26c == 0x10) && ((DAT_02854d14 & 1) == 0)) {
    puVar2 = (undefined4 *)*DAT_02854d10;
    *DAT_02854d10 = (int)(puVar2 + 0x18);
    DAT_02854d14 = DAT_02854d14 + 4;
    puVar2[0xc] = puVar2[-0xc];
    *puVar2 = puVar2[-6];
    puVar2[0xd] = puVar2[-5];
    puVar2[1] = puVar2[-5];
    puVar2[0xe] = puVar2[-4];
    puVar2[2] = puVar2[-4];
    puVar2[0x10] = puVar2[-8];
    puVar2[3] = puVar2[-3];
    puVar2[0x11] = puVar2[-1];
    puVar2[4] = puVar2[-2];
    puVar2[5] = puVar2[-1];
    puVar2[6] = puVar2[-6];
    puVar2[7] = puVar2[-5];
    puVar2[8] = puVar2[-4];
    puVar2[9] = puVar2[-3];
    puVar2[-6] = *puVar2;
    puVar2[10] = puVar2[-2];
    puVar2[-5] = puVar2[-0xb];
    puVar2[0xb] = puVar2[-1];
    puVar2[-4] = puVar2[-10];
    puVar2[0xf] = puVar2[-3];
    puVar2[-2] = puVar2[4];
    puVar2[0x12] = puVar2[-0xc];
    puVar2[-1] = puVar2[-7];
    puVar2[-3] = puVar2[-9];
    puVar2[0x13] = puVar2[-0xb];
    puVar2[0x14] = puVar2[-10];
    puVar2[0x15] = puVar2[-9];
    puVar2[0x16] = puVar2[-8];
    puVar2[0x17] = puVar2[-7];
  }
  return;
}

