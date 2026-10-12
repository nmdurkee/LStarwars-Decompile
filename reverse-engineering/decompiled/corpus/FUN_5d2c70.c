/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d2c70; label: FUN_005d2c70
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

