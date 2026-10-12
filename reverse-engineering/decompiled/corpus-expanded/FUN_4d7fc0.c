/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d7fc0; label: FUN_004d7fc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d7fc0(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_6c;
  float local_68;
  float local_64;
  undefined4 local_54;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_30;
  
  iVar4 = 0;
  iVar3 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if (*(char *)(iVar3 + 0x7b5) == 'G') {
        if (*(char *)(iVar3 + 0x7b8) == '\0') {
          FUN_004d6f20();
          local_54 = 0xffffffff;
          iVar1 = *(int *)(iVar3 + 0x798);
          local_48 = *(float *)(iVar1 + 0x38);
          local_44 = *(float *)(iVar1 + 0x3c);
          local_40 = *(float *)(iVar1 + 0x40);
          if (0.2 <= *(float *)(iVar3 + 0x77c)) {
            local_30 = 0xff808080;
          }
          else {
            fVar2 = *(float *)(iVar3 + 0x77c) / 0.2;
            local_30 = 0xff808080;
            local_48 = fVar2 * (local_48 - local_6c) + local_6c;
            local_44 = local_68 + fVar2 * (local_44 - local_68);
            local_40 = local_64 + (local_40 - local_64) * fVar2;
          }
LAB_004d8125:
          FUN_004d7930(&local_6c,&local_48,0x3f800000,DAT_00881c34,*(undefined4 *)(iVar3 + 0x77c),
                       0x3e4ccccd,0x40600000,0x3f800000);
        }
      }
      else if (*(char *)(iVar3 + 0x7b5) == '5') {
        local_54 = 0xffffffff;
        local_30 = 0xff808080;
        local_48 = *(float *)(iVar3 + 0x748);
        local_44 = *(float *)(iVar3 + 0x74c);
        local_40 = *(float *)(iVar3 + 0x750);
        if (*(short *)(iVar3 + 0x1064) != DAT_007f1ac4) {
          FUN_004d6f20();
          goto LAB_004d8125;
        }
        local_6c = *(float *)(iVar3 + 0x5c);
        local_68 = *(float *)(iVar3 + 0x60);
        local_64 = *(float *)(iVar3 + 100);
        FUN_005dbed0(&local_6c,DAT_0093b108,0);
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x10d8;
    } while (iVar4 < DAT_0093d500);
  }
  return;
}

