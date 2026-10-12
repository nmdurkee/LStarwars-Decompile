/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55d1e0; label: FUN_0055d1e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055d1e0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint *puVar4;
  int iVar5;
  float10 fVar6;
  
  fVar1 = *(float *)(PTR_DAT_008021b4 + 0x11c);
  fVar2 = *(float *)(PTR_DAT_008021b4 + 0x120);
  fVar3 = *(float *)(PTR_DAT_008021b4 + 0x124);
  iVar5 = 0;
  if (0 < DAT_0093d500) {
    puVar4 = (uint *)(DAT_0093d504 + 0x1fc);
    do {
      if (((*puVar4 & 1) != 0) && ((*puVar4 & 0x1000) != 0)) {
        fVar6 = (float10)FUN_005c0240((fVar3 - (float)puVar4[-0x66]) *
                                      (fVar3 - (float)puVar4[-0x66]) +
                                      (fVar1 - (float)puVar4[-0x68]) *
                                      (fVar1 - (float)puVar4[-0x68]) +
                                      (fVar2 - (float)puVar4[-0x67]) *
                                      (fVar2 - (float)puVar4[-0x67]));
        puVar4[0x388] = (uint)(float)fVar6;
      }
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 0x436;
    } while (iVar5 < DAT_0093d500);
  }
  return;
}

