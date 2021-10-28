<template>
  <div class="avatar-wrapper" :style="[style, customStyle]" aria-hidden="true">
    <img :src="this.src" alt="">
  </div>
</template>

<script>
export default {
  data() {
    return {
      backgroundColors: [
        '#F44336', '#FF4081', '#9C27B0', '#673AB7',
        '#3F51B5', '#2196F3', '#03A9F4', '#00BCD4', '#009688',
        '#4CAF50', '#8BC34A', '#CDDC39', /* '#FFEB3B' , */ '#FFC107',
        '#FF9800', '#FF5722', '#795548', '#9E9E9E', '#607D8B'],
      imgError: false,
    }
  },
}
</script>

<style scoped>

</style>