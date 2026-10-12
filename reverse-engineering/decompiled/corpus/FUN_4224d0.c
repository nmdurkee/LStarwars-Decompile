/* Ghidra analysis pseudocode, not original source.
 * ev_fc46cff07f0ed537c3533760820ac45bd355561daa184f1b787f47d220e25ab8
 * Entry: 0x4224d0; label: FUN_004224d0
 */

void FUN_004224d0(float param_1)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  float fVar5;
  undefined1 *puVar6;
  int in_ECX;
  undefined1 *puVar7;
  undefined1 *puVar8;
  float10 fVar9;
  undefined8 uVar10;
  float local_24;
  int local_14;
  int local_c;
  
  puVar8 = (undefined1 *)(in_ECX + 0xd8);
  local_c = 0xc;
  do {
    if (*(int *)(puVar8 + 0x120) != 0) {
      uVar1 = *(undefined4 *)(puVar8 + 0x104);
      cVar4 = puVar8[0x124];
      local_24 = *(float *)(puVar8 + 0x108);
      fVar2 = *(float *)(puVar8 + 0x110);
      fVar3 = *(float *)(puVar8 + 0x114);
      if (puVar8[0x125] == '\0') {
        fVar5 = *(float *)(puVar8 + 0x100) - (param_1 + param_1);
        *(float *)(puVar8 + 0x100) = fVar5;
        if (fVar5 < 0.0) {
          *(undefined4 *)(puVar8 + 0x120) = 0;
          goto LAB_00422715;
        }
      }
      else {
        puVar8[0x125] = 0;
        fVar5 = *(float *)(puVar8 + 0x100) + param_1 + param_1;
        *(float *)(puVar8 + 0x100) = fVar5;
        if (1.0 < fVar5) {
          *(undefined4 *)(puVar8 + 0x100) = 0x3f800000;
        }
      }
      uVar10 = FUN_004208a0(*(undefined4 *)(puVar8 + 0x100),*(undefined4 *)(puVar8 + 0x11c));
      if (*(float *)(puVar8 + 0x118) <= 0.0) {
        FUN_00422340(puVar8,uVar1,local_24,0,(int)((ulonglong)uVar10 >> 0x20),fVar2,fVar3,
                     (int)uVar10,1,0);
      }
      else {
        FUN_005eaad0(*(undefined4 *)(in_ECX + 0xa0),*(float *)(in_ECX + 0x30) * fVar2,
                     *(float *)(in_ECX + 0x34) * fVar3);
        fVar9 = (float10)FUN_005d0e80(*(undefined4 *)(in_ECX + 0xa0));
        local_14 = FUN_0050e7a0(puVar8,*(undefined4 *)(puVar8 + 0x118));
        local_24 = local_24 - (float)local_14 * (float)(fVar9 * (float10)0.800000011920929) * 0.5;
        puVar7 = puVar8;
        if (0 < local_14) {
          do {
            puVar6 = (undefined1 *)FUN_004f1f90(puVar7,10);
            if (puVar6 != (undefined1 *)0x0) {
              *puVar6 = 0;
            }
            FUN_00422340(puVar7,uVar1,local_24,0,(int)cVar4,fVar2,fVar3,(int)uVar10,1,0);
            if (puVar6 != (undefined1 *)0x0) {
              *puVar6 = 0x20;
              local_24 = local_24 + (float)(fVar9 * (float10)0.800000011920929);
              puVar7 = puVar6 + 1;
            }
            local_14 = local_14 + -1;
          } while (local_14 != 0);
        }
      }
    }
LAB_00422715:
    puVar8 = puVar8 + 0x128;
    local_c = local_c + -1;
    if (local_c == 0) {
      return;
    }
  } while( true );
}

