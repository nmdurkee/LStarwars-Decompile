/* Ghidra pseudocode, not original source.
 * ev_1545e5b34141c1614daa034024a98821bd7642306100b3a505193274c33334db
 * Entry: 0x4e2770; label: FUN_004e2770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e2770(undefined4 param_1)

{
  undefined4 uVar1;
  
  if ((DAT_0087aa20 == '\0') &&
     ((((DAT_0093d7f0 != 0 && (*(char *)(DAT_0093d7f0 + 0x671) == '\0')) &&
       (12.1 < *(float *)(DAT_0093d7f0 + 0x69c))) ||
      (((DAT_0093d7f4 != 0 && (*(char *)(DAT_0093d7f4 + 0x671) == '\0')) &&
       (12.1 < *(float *)(DAT_0093d7f4 + 0x69c))))))) {
    if (DAT_00951b50 == 0) {
      uVar1 = FUN_005756c0(param_1,"gunshipa_mid");
      FUN_00575f10(uVar1);
      DAT_008894bc = 1;
      FUN_0048f990(param_1);
      DAT_008894bc = 0;
    }
    DAT_0087aa20 = '\x01';
  }
  if ((DAT_00889098 == 0) &&
     (((DAT_0093d7f0 != 0 && (*(char *)(DAT_0093d7f0 + 0x28b) != '\0')) ||
      ((DAT_0093d7f4 != 0 && (*(char *)(DAT_0093d7f4 + 0x28b) != '\0')))))) {
    DAT_00889098 = 1;
    FUN_0057a620(param_1,"ep2_bonus_gunshipcavalry_explode",1);
  }
  return;
}

