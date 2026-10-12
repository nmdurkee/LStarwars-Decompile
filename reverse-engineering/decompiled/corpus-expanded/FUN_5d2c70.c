/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d2c70; label: FUN_005d2c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d2c70(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  short *psVar6;
  
  puVar4 = DAT_009738d8;
  do {
    if (puVar4 == (undefined4 *)0x0) {
      return;
    }
    for (puVar1 = (undefined4 *)*puVar4; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1
        ) {
      iVar5 = 0;
      piVar2 = (int *)puVar1[5];
      if ((((piVar2 != (int *)0x0) && (piVar2 != param_2)) && (iVar3 = *piVar2, iVar3 != 0)) &&
         (0 < *(int *)(iVar3 + 0x1b0))) {
        psVar6 = (short *)(iVar3 + 0x130);
        do {
          if (*psVar6 == param_1) {
            piVar2[1] = (int)*(short *)(iVar3 + 0x170 + iVar5 * 2);
            piVar2[0x36] = 0;
            piVar2[0x33] = 0;
            piVar2[0x22] = 0;
            break;
          }
          iVar5 = iVar5 + 1;
          psVar6 = psVar6 + 1;
        } while (iVar5 < *(int *)(iVar3 + 0x1b0));
      }
    }
    puVar4 = (undefined4 *)puVar4[1];
  } while( true );
}

