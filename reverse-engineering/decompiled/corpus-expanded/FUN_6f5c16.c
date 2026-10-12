/* Ghidra pseudocode, not original source.
 * ev_bde5c5f75e817edbac891f5cdb42210190c78104eb02ca0378b00d023a3e9188
 * Entry: 0x6f5c16; label: FUN_006f5c16
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

undefined4 * FUN_006f5c16(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  puVar6 = (undefined4 *)0x0;
  __lock(1);
  iVar5 = 0;
  do {
    puVar7 = puVar6;
    if (DAT_029aac80 <= iVar5) {
LAB_006f5d0c:
      if (puVar7 != (undefined4 *)0x0) {
        puVar7[3] = puVar7[3] & 0x8000;
        puVar7[1] = 0;
        puVar7[2] = 0;
        *puVar7 = 0;
        puVar7[7] = 0;
        puVar7[4] = 0xffffffff;
      }
      FUN_006f5d3d();
      return puVar7;
    }
    piVar1 = (int *)(DAT_029a9c60 + iVar5 * 4);
    if (*piVar1 == 0) {
      iVar5 = iVar5 * 4;
      pvVar4 = __malloc_crt(0x38);
      *(void **)(iVar5 + DAT_029a9c60) = pvVar4;
      if (*(int *)(DAT_029a9c60 + iVar5) != 0) {
        iVar3 = ___crtInitCritSecAndSpinCount(*(int *)(DAT_029a9c60 + iVar5) + 0x20,4000);
        if (iVar3 == 0) {
          _free(*(void **)(iVar5 + DAT_029a9c60));
          *(undefined4 *)(iVar5 + DAT_029a9c60) = 0;
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar5 + DAT_029a9c60) + 0x20));
          puVar7 = *(undefined4 **)(iVar5 + DAT_029a9c60);
        }
      }
      goto LAB_006f5d0c;
    }
    uVar2 = *(uint *)(*piVar1 + 0xc);
    if (((uVar2 & 0x83) == 0) && (-1 < (short)uVar2)) {
      if ((iVar5 - 3U < 0x11) && (iVar3 = __mtinitlocknum(iVar5 + 0x10), iVar3 == 0))
      goto LAB_006f5d0c;
      FUN_006e82ea(iVar5,*(undefined4 *)(DAT_029a9c60 + iVar5 * 4));
      puVar7 = *(undefined4 **)(DAT_029a9c60 + iVar5 * 4);
      if ((*(byte *)(puVar7 + 3) & 0x83) == 0) goto LAB_006f5d0c;
      FUN_006e834e(iVar5,puVar7);
    }
    iVar5 = iVar5 + 1;
  } while( true );
}

