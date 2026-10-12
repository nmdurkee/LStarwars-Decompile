/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x427b40; label: FUN_00427b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00427b40(int param_1)

{
  char cVar1;
  float fVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1 + 0x7b5);
  if ((cVar1 == '#') || (cVar1 == '$')) {
    fVar2 = *(float *)(param_1 + 0x77c) + _DAT_00925018;
    *(float *)(param_1 + 0x77c) = fVar2;
    if (*(float *)(param_1 + 0x784) < fVar2 == (*(float *)(param_1 + 0x784) == fVar2)) {
      if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0a0) {
        iVar3 = DAT_0093d7f0;
        if (param_1 == DAT_0093d7f0) {
          iVar3 = DAT_0093d7f4;
        }
        *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(iVar3 + 0x5c);
        *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(iVar3 + 0x60);
        *(undefined4 *)(param_1 + 100) = *(undefined4 *)(iVar3 + 100);
      }
    }
    else {
      if (cVar1 == '$') {
        iVar3 = DAT_0093d7f0;
        if (param_1 == DAT_0093d7f0) {
          iVar3 = DAT_0093d7f4;
        }
        *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(iVar3 + 0x5c);
        *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(iVar3 + 0x60);
        *(undefined4 *)(param_1 + 100) = *(undefined4 *)(iVar3 + 100);
      }
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0) {
        *(undefined1 *)(param_1 + 0x281) = 0;
        *(undefined4 *)(param_1 + 0x6c) = 0xbdcccccd;
        return;
      }
    }
  }
  return;
}

