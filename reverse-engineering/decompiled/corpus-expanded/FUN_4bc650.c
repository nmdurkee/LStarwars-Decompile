/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bc650; label: FUN_004bc650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bc650(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 local_80 [56];
  float local_48;
  undefined1 local_40 [56];
  float local_8;
  
  DAT_0087b9c0 = 0;
  _DAT_0087b9c4 = 0;
  DAT_0087b9c0 = FUN_00440120(*(undefined4 *)(param_1 + 0x2ae8),"ai_zam");
  iVar1 = *(int *)(param_1 + 0x5168);
  if (iVar1 != 0) {
    iVar2 = 0;
    *(undefined1 *)(iVar1 + 0x77e3) = 0;
    if ('\0' < *(char *)(iVar1 + 0x77e0)) {
      puVar3 = (undefined1 *)(iVar1 + 0x13a);
      do {
        if (DAT_007fc454 == 0) {
LAB_004bc723:
          *puVar3 = 0;
        }
        else {
          FUN_005526c0(puVar3 + -0x13a,0x3f800000,local_40,1);
          FUN_005526c0(puVar3 + -0x13a,*(undefined4 *)(puVar3 + -0x12a),local_80,1);
          if (_DAT_007fc450 <= local_8) {
            if (local_48 <= _DAT_007fc450) goto LAB_004bc723;
            *puVar3 = 1;
          }
          else {
            if (_DAT_007fc450 <= local_48) goto LAB_004bc723;
            *puVar3 = 0xff;
          }
        }
        iVar2 = iVar2 + 1;
        puVar3 = puVar3 + 0x140;
      } while (iVar2 < *(char *)(iVar1 + 0x77e0));
    }
  }
  return;
}

