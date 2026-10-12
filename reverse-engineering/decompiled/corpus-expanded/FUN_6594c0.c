/* Ghidra pseudocode, not original source.
 * ev_04b6c5fb0da19ab46b9dcd6e2bf7aaf6621f6765e7317b7c56ac1531caca2973
 * Entry: 0x6594c0; label: FUN_006594c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006594c0(float param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  float local_24;
  float local_20;
  float local_1c;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  if ((DAT_02923194 != -1) && (DAT_02962010 != -1)) {
    FUN_005da860(local_c,DAT_02962114,DAT_02923194);
    uVar3 = FUN_005cf9c0(local_c);
    if (DAT_0292fd08 != -1) {
      FUN_005b37d0(local_18,uVar3,&DAT_0292ff14 + DAT_02962010 * 0xb5 + DAT_0292fd08 * 3);
      FUN_005b3800(&local_24,&DAT_0292fda8,local_18);
      if (local_1c * local_1c + local_24 * local_24 + local_20 * local_20 == 0.0) {
        return;
      }
    }
    DAT_0292fd08 = -1;
    iVar4 = 0;
    if (0 < (int)(&DAT_0292fe1c)[DAT_02962010 * 0xb5]) {
      iVar5 = 0;
      do {
        FUN_005b37d0(local_18,uVar3,(int)&DAT_0292ff14 + DAT_02962010 * 0x2d4 + iVar5);
        FUN_005b3800(&local_24,&DAT_0292fda8,local_18);
        fVar1 = local_1c * local_1c + local_24 * local_24 + local_20 * local_20;
        iVar2 = iVar4;
        if ((0.0 <= param_1) && (param_1 <= fVar1)) {
          iVar2 = DAT_0292fd08;
          fVar1 = param_1;
        }
        param_1 = fVar1;
        DAT_0292fd08 = iVar2;
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0xc;
      } while (iVar4 < (int)(&DAT_0292fe1c)[DAT_02962010 * 0xb5]);
    }
    return;
  }
  DAT_0292fd08 = 0xffffffff;
  return;
}

